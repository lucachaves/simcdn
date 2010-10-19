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

#define CDN_CENTRALUNIT_REPLY_CC
#include "CDN_CentralUnit_Reply.h"
#include <assert.h>
void CDN_CentralUnit_Reply::setServerGate(cGate* serverGate){
	assert(serverGate);
	this->_serverGate = serverGate;
}
cGate* CDN_CentralUnit_Reply::getServerGate(){
	return this->_serverGate;
}
