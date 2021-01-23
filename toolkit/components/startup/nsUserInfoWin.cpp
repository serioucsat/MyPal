/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "nsUserInfo.h"

#include "mozilla/ArrayUtils.h" // ArrayLength
#include "nsString.h"
#include "windows.h"
#include "nsCRT.h"
#include "nsXPIDLString.h"

#define SECURITY_WIN32
#include "lm.h"
#include "security.h"

nsUserInfo::nsUserInfo()
{
}

nsUserInfo::~nsUserInfo()
{
}

NS_IMPL_ISUPPORTS(nsUserInfo, nsIUserInfo)

NS_IMETHODIMP
nsUserInfo::GetUsername(char **aUsername)
{
  *aUsername = ToNewUTF8String(NS_LITERAL_STRING(""));
  return *aUsername ? NS_OK : NS_ERROR_FAILURE;
}

NS_IMETHODIMP
nsUserInfo::GetFullname(char16_t **aFullname)
{
  *aFullname = ToNewUnicode(NS_LITERAL_STRING(""));
  return *aFullname ? NS_OK : NS_ERROR_FAILURE;
}

NS_IMETHODIMP
nsUserInfo::GetDomain(char **aDomain)
{
  *aDomain = ToNewUTF8String(NS_LITERAL_STRING(""));
  return *aDomain ? NS_OK : NS_ERROR_FAILURE;
}

NS_IMETHODIMP
nsUserInfo::GetEmailAddress(char **aEmailAddress)
{
  *aEmailAddress = ToNewUTF8String(NS_LITERAL_STRING(""));
  return *aEmailAddress ? NS_OK : NS_ERROR_FAILURE;
}
