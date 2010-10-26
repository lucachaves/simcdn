//This file is part of CDNsim.

//CDNsim is free software; you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation; either version 2 of the License, or
//(at your option) any later version.

//CDNsim is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

//You should have received a copy of the GNU General Public License
//along with CDNsim; if not, write to the Free Software
//Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
package src.simulator.genericNode.contentExchange.static;

simple StaticContentExchange_ServicePeer
{
    parameters:
        string cacheType = default("LRU");
        string cacheContents = default("NULL");
        string cacheSizeInMbs = default("0.0");
        volatile double shrink = default(0);
        string objectsReference = default("./dataset/objects");

    gates:
        input fromCDN_RequestsAssignerReceiverToClientUnit;
        input fromCDN_RequestsAssignerReceiverToServerUnit;
        input fromClientUnitOrServerUnit;
}
