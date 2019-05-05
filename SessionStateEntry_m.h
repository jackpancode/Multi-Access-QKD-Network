//
// Generated file, do not edit! Created by nedtool 5.4 from SessionStateEntry.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __SESSIONSTATEENTRY_M_H
#define __SESSIONSTATEENTRY_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0504
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>SessionStateEntry.msg:16</tt> by nedtool.
 * <pre>
 * //
 * // This program is free software: you can redistribute it and/or modify
 * // it under the terms of the GNU Lesser General Public License as published by
 * // the Free Software Foundation, either version 3 of the License, or
 * // (at your option) any later version.
 * // 
 * // This program is distributed in the hope that it will be useful,
 * // but WITHOUT ANY WARRANTY; without even the implied warranty of
 * // MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * // GNU Lesser General Public License for more details.
 * // 
 * // You should have received a copy of the GNU Lesser General Public License
 * // along with this program.  If not, see http://www.gnu.org/licenses/.
 * //
 * packet SessionStateEntry
 * {
 *     int sessionId;
 *     string srcMac;
 *     string srcQMac;
 *     string srcSubInterface;
 *     string desMac;
 *     string desQMac;
 *     string desSubInterface;
 *     string expiry;
 *     string status;
 * }
 * </pre>
 */
class SessionStateEntry : public ::omnetpp::cPacket
{
  protected:
    int sessionId;
    ::omnetpp::opp_string srcMac;
    ::omnetpp::opp_string srcQMac;
    ::omnetpp::opp_string srcSubInterface;
    ::omnetpp::opp_string desMac;
    ::omnetpp::opp_string desQMac;
    ::omnetpp::opp_string desSubInterface;
    ::omnetpp::opp_string expiry;
    ::omnetpp::opp_string status;

  private:
    void copy(const SessionStateEntry& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SessionStateEntry&);

  public:
    SessionStateEntry(const char *name=nullptr, short kind=0);
    SessionStateEntry(const SessionStateEntry& other);
    virtual ~SessionStateEntry();
    SessionStateEntry& operator=(const SessionStateEntry& other);
    virtual SessionStateEntry *dup() const override {return new SessionStateEntry(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getSessionId() const;
    virtual void setSessionId(int sessionId);
    virtual const char * getSrcMac() const;
    virtual void setSrcMac(const char * srcMac);
    virtual const char * getSrcQMac() const;
    virtual void setSrcQMac(const char * srcQMac);
    virtual const char * getSrcSubInterface() const;
    virtual void setSrcSubInterface(const char * srcSubInterface);
    virtual const char * getDesMac() const;
    virtual void setDesMac(const char * desMac);
    virtual const char * getDesQMac() const;
    virtual void setDesQMac(const char * desQMac);
    virtual const char * getDesSubInterface() const;
    virtual void setDesSubInterface(const char * desSubInterface);
    virtual const char * getExpiry() const;
    virtual void setExpiry(const char * expiry);
    virtual const char * getStatus() const;
    virtual void setStatus(const char * status);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SessionStateEntry& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SessionStateEntry& obj) {obj.parsimUnpack(b);}


#endif // ifndef __SESSIONSTATEENTRY_M_H

