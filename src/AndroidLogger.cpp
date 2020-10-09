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



#include "AndroidLogger.h"

#include <cutils/log.h>

namespace ningbo {

AndroidLogger::AndroidLogger(std::string logtag
				    			, std::string funcName
				    			, int line 
				    			, std::string prefixBeforeFuncName)
: mLogtag(logtag)
, mFuncName(funcName)
, mLine(line)
, mPrefixBeforeFuncName(prefixBeforeFuncName)
{

}

bool AndroidLogger::outputWhenConstruct()
{
	__android_log_print(ANDROID_LOG_DEBUG, mLogtag.c_str(), "L%4d| +| %s%s|", mLine, mPrefixBeforeFuncName.c_str(), mFuncName.c_str());
	return true;
}

bool AndroidLogger::outputWhenDeConstruct()
{
	__android_log_print(ANDROID_LOG_DEBUG, mLogtag.c_str(), "L%4d| -| %s%s|", mLine, mPrefixBeforeFuncName.c_str(), mFuncName.c_str());
	return true;
}


}