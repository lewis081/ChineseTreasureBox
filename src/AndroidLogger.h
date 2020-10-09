/*
**
** Copyright 2020, The Ningbo Big East Seashore Open Source Project(NBBESOSP)
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
**
** Authors:
** Liu Yi <lewis081@126.com>
** Create Date: 2020-09-30
*/


#ifndef NINGBO_ANDROID_H
#define NINGBO_ANDROID_H

#include "Tools.h"


namespace ningbo {


#define ACR \
	AutoConstructRelease AutoConstructRelease(std::make_shared<AndroidLogger>(LOG_TAG, __FUNCTION__, __LINE__));

#define ACR_BECALLED \
	AutoConstructRelease AutoConstructRelease(std::make_shared<AndroidLogger>(LOG_TAG, __FUNCTION__, __LINE__, "[<--]"));




class AndroidLogger : public IMPLEMENT_NB Logger
{
public:
	AndroidLogger(std::string logtag
    				, std::string funcName
    				, int line 
    				, std::string prefixBeforeFuncName = "");

	virtual bool outputWhenConstruct() override;
	virtual bool outputWhenDeConstruct() override;
	
private:
	std::string mLogtag;
	std::string mFuncName;
	int mLine;
	std::string mPrefixBeforeFuncName;	
};

}

#endif