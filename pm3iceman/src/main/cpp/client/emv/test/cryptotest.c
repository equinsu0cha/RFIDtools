//-----------------------------------------------------------------------------
// Copyright (C) 2017 Merlok
//
// This code is licensed to you under the terms of the GNU GPL, version 2 or,
// at your option, any later version. See the LICENSE.txt file for the text of
// the license.
//-----------------------------------------------------------------------------
// Crypto algorithms testing
//-----------------------------------------------------------------------------

#include <common/polarssl/bignum.h>
#include <common/polarssl/aes.h>
#include <common/polarssl/des.h>
#include <common/polarssl/sha1.h>
#include <common/polarssl/rsa.h>
#include "cryptotest.h"
#include "util.h"
#include "ui.h"

#include "bignum.h"
#include "aes.h"
#include "des.h"
#include "rsa.h"
#include "sha1.h"

#include "crypto_test.h"
#include "sda_test.h"
#include "dda_test.h"
#include "cda_test.h"

int ExecuteCryptoTests(bool verbose) {
	int res;
	bool TestFail = false;
	
	res = mpi_self_test(verbose);
	if (res) TestFail = true;
	
	res = aes_self_test(verbose);
	if (res) TestFail = true;
	
	res = des_self_test(verbose);
	if (res) TestFail = true;
	
	res = sha1_self_test(verbose);
	if (res) TestFail = true;
	
	res = rsa_self_test(verbose);
	if (res) TestFail = true;
	
	res = exec_sda_test(verbose);
	if (res) TestFail = true;

	res = exec_dda_test(verbose);
	if (res) TestFail = true;
	
	res = exec_cda_test(verbose);
	if (res) TestFail = true;

	res = exec_crypto_test(verbose);
	if (res) TestFail = true;

	PrintAndLogEx(NORMAL, "\n--------------------------");
	if (TestFail)
		PrintAndLogEx(ERR, "Test(s) [ERROR].");
	else
		PrintAndLogEx(SUCCESS, "Tests [OK].");
	
	return TestFail;
}

