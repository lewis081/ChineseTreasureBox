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


#ifndef NINGBO_TOOLS_H
#define NINGBO_TOOLS_H

#include <string>
#include <memory>






namespace ningbo {

#define INTERFACE_NB

#define IMPLEMENT_NB


class INTERFACE_NB Logger
{
public:
	virtual ~Logger() {}
	virtual bool outputWhenConstruct() = 0;
	virtual bool outputWhenDeConstruct() = 0;
};


class AutoConstructRelease
{
public:
    AutoConstructRelease(std::shared_ptr<Logger> logger);
    ~AutoConstructRelease();

private:
	std::shared_ptr<Logger> mLogger;
};

}

#endif