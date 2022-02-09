/**
 * @file
 * @brief Tests implementation
 * @defgroup cred_storage_test
 * @{
 */

#include <gtest/gtest.h>

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */
#include "cred_storage.c"
#if defined(__cplusplus)
}
#endif /* __cplusplus */

#define USERNAME "Admin"
#define PASSWORD "very_strong_password"

TEST(CredStorageTest, saveCreds)
{
  credentials_t credentials = { 0 };
  strcpy(credentials.username, USERNAME);
  strcpy(credentials.password, PASSWORD);
  cred_storage_ret_values res = cred_storage_save_credentials(&credentials);
  EXPECT_EQ(CRED_ST_RET_OK, res);
  EXPECT_STREQ(USERNAME, g_credentials.username);
  EXPECT_STREQ(PASSWORD, g_credentials.password);
}

TEST(CredStorageTest, readCreds)
{
  static credentials_t credentials = { 0 };
  strcpy(credentials.username, USERNAME);
  strcpy(credentials.password, PASSWORD);
  cred_storage_ret_values res = cred_storage_save_credentials(&credentials);
  EXPECT_EQ(CRED_ST_RET_OK, res);
  credentials.username[0] = '\0';
  credentials.password[0] = '\0';
  res = cred_storage_read_credentials(&credentials);
  EXPECT_EQ(CRED_ST_RET_OK, res);
  EXPECT_STREQ(USERNAME, credentials.username);
  EXPECT_STREQ(PASSWORD, credentials.password);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

/** @} */