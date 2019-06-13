/*
 * ClientQSGenerator.cc
 *
 *  Created on: 7 Apr 2019
 *      Author: Faisal
 */

#include <stdio.h>
#include <string.h>
#include <omnetpp.h>
#include <bitset>
#include <iostream>
#include <random>

using namespace omnetpp;

class QuantumStatesGenerator : public cSimpleModule
{
protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    std::string siftKey(std::string states);
    std::string statesStatus(std::string states);
private:
    int randomGate;
    int counter;
    cQueue xQueue;
    std::string receivedPolarization;
    std::string polarizationSFilters;
    std::string polarizationRFilters;
};

Define_Module(QuantumStatesGenerator);

void QuantumStatesGenerator::initialize()
{
    counter = this->getParentModule()->getParentModule()->par("initKeyLength").intValue();
}

void QuantumStatesGenerator::handleMessage(cMessage *msg)
{
    /*
     * Gate DL,  Bit Value 0,    Polarisation State \
     * Gate V,   Bit Value 0,    Polarisation State |
     * Gate DR,  Bit Value 1,    Polarisation State /
     * Gate H,   Bit Value 1,    Polarisation State -
     */

    cGate *gate = msg->getArrivalGate();
    if(gate->isName("processorCommunication$i"))
    {
        cQueue queue("quantumStatesQueue");
        std::string key = msg->par("value").stringValue();
        delete msg;
        char *stat = new char[key.length()+1];

        strcpy(stat, key.c_str());
        for(int i=0; i<key.length(); i++)
        {
            std::string j = std::string(1, stat[i]);
            std::string polarization;
            if (j == "0") {
                randomGate = (rand() % 2) + 0;
            }
            else {
                randomGate = (rand() % 2) + 0;
                randomGate = randomGate + 2;
            }
            cMessage *quantumState = new cMessage(j.c_str());

            queue.insert(quantumState);
            while (!queue.isEmpty()) {

                msg = (cMessage *) queue.pop();
                std::string exitGate = "";
                if(randomGate == 0)
                {
                    exitGate = "DL";
                }
                else if(randomGate == 1)
                {
                    exitGate = "V";
                }
                else if(randomGate == 2)
                {
                    exitGate = "DR";
                }
                else if (randomGate == 3)
                {
                    exitGate = "H";
                }
                sendDelayed(msg,0,exitGate.c_str());
            }

            if (randomGate == 0) {
                polarizationSFilters.append("\\");
            }
            else if (randomGate == 1) {
                polarizationSFilters.append("|");
            }
            else if (randomGate == 2) {
                polarizationSFilters.append("/");
            }
            else if (randomGate == 3) {
                polarizationSFilters.append("-");
            }
        }
        cPacket *polarizationFilters = new cPacket("polarizationFilterUsed");
        polarizationFilters->addPar("type").setStringValue("pfilter");
        polarizationFilters->addPar("polarizationFilterUsed").setStringValue(polarizationSFilters.c_str());

        send(polarizationFilters,"processorCommunication$o");
    }
    else
    {
        counter--;
        if(counter >= 0)
        {
            if(gate->isName("Diagonal"))
            {
                polarizationRFilters.append("x");
            }
            else if(gate->isName("Straight"))
            {
                polarizationRFilters.append("+");
            }
            receivedPolarization.append(msg->getName());

            if(counter == 0)
            {
                cPacket *quantumData = new cPacket("quantumData");
                quantumData->addPar("type").setStringValue("quantumData");
                quantumData->addPar("siftedKey").setStringValue(QuantumStatesGenerator::siftKey(receivedPolarization).c_str());
                quantumData->addPar("filterUsage").setStringValue(polarizationRFilters.c_str());
                send(quantumData,"processorCommunication$o");
            }
            delete msg;
        }
    }
}

std::string QuantumStatesGenerator::siftKey(std::string states)
{
    std::string siftedKey;
    char polarization[states.length()+1];
    strcpy(polarization, states.c_str());
    for(int i=0; i<strlen(polarization); i++)
    {
        if(polarization[i] != '0')
        {
            if(polarization[i] == '\\' || polarization[i] == '|')
            {
                siftedKey.append("0");
            }
            else if (polarization[i] == '/' || polarization[i] == '-')
            {
                siftedKey.append("1");
            }
        }
    }
    return siftedKey;
}

std::string QuantumStatesGenerator::statesStatus(std::string states)
{
    std::string statesUsed;
    char polarization[states.length()+1];
    strcpy(polarization, states.c_str());
    for(int i=0; i<strlen(polarization); i++)
    {
        if(polarization[i] != '0')
        {
            statesUsed.append("1");
        }
        else
        {
            statesUsed.append("0");
        }
    }
    return statesUsed;
}






