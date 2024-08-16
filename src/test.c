#include "./tests_suite/additional/additional_test_suite.h"
#include "./tests_suite/calculation/calculation_test_suite.h"
#include "./tests_suite/compare/compare_test_suite.h"
#include "./tests_suite/copy/copy_test_suite.h"
#include "./tests_suite/search/search_test_suite.h"
#include "./tests_suite/special/special_test_suite.h"
#include "./tests_suite/sprintf/sprintf_test_suite.h"
#include "./tests_suite/sscanf/sscanf_test_suite.h"
#include "s21_string.h"

int run_test_suite(Suite *(*suite_func)()) {
  Suite *s = suite_func();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return number_failed;
}

int main(int argc, char **argv) {
  int number_failed = 0;

  if (argc > 1) {
    // ==== ADDITIONAL FUNCTION TESTS ====
    if (strcmp(argv[1], "strtok") == 0) {
      printf("\nSTRTOK TESTS\n");
      number_failed += run_test_suite(strtok_suite);
    } else if (strcmp(argv[1], "strerror") == 0) {
      printf("\nSTRERROR TESTS\n");
      number_failed += run_test_suite(strerror_suite);
    } else if (strcmp(argv[1], "strncat") == 0) {
      printf("\nSTRNCAT TESTS\n");
      number_failed += run_test_suite(strncat_suite);
    }
    // ==== CALCULATION FUNCTION TESTS ====
    else if (strcmp(argv[1], "strcspn") == 0) {
      printf("\nSTRCSPN TESTS\n");
      number_failed += run_test_suite(strcspn_suite);
    } else if (strcmp(argv[1], "strlen") == 0) {
      printf("\nSTRLEN TESTS\n");
      number_failed += run_test_suite(strlen_suite);
    }
    // ==== COMPARE FUNCTION TESTS ====
    else if (strcmp(argv[1], "memcmp") == 0) {
      printf("\nMEMCMP TESTS\n");
      number_failed += run_test_suite(memcmp_suite);
    } else if (strcmp(argv[1], "strncmp") == 0) {
      printf("\nSTRNCMP TESTS\n");
      number_failed += run_test_suite(strncmp_suite);
    }
    // ==== COPY FUNCTION TESTS ====
    else if (strcmp(argv[1], "memcpy") == 0) {
      printf("\nMEMCPY TESTS\n");
      number_failed += run_test_suite(memcpy_suite);
    } else if (strcmp(argv[1], "memset") == 0) {
      printf("\nMEMSET TESTS\n");
      number_failed += run_test_suite(memset_suite);
    } else if (strcmp(argv[1], "strncpy") == 0) {
      printf("\nSTRNCPY TESTS\n");
      number_failed += run_test_suite(strncpy_suite);
    }
    // ==== SEARCH FUNCTION TESTS ====
    else if (strcmp(argv[1], "memchr") == 0) {
      printf("\nMEMCHR TESTS\n");
      number_failed += run_test_suite(memchr_suite);
    } else if (strcmp(argv[1], "strchr") == 0) {
      printf("\nSTRCHR TESTS\n");
      number_failed += run_test_suite(strchr_suite);
    } else if (strcmp(argv[1], "strpbrk") == 0) {
      printf("\nSTRPBRK TESTS\n");
      number_failed += run_test_suite(strpbrk_suite);
    } else if (strcmp(argv[1], "strrchr") == 0) {
      printf("\nSTRRCHR TESTS\n");
      number_failed += run_test_suite(strrchr_suite);
    } else if (strcmp(argv[1], "strstr") == 0) {
      printf("\nSTRSTR TESTS\n");
      number_failed += run_test_suite(strstr_suite);
    }
    // ==== SPECIAL FUNCTION TESTS ====
    else if (strcmp(argv[1], "insert") == 0) {
      printf("\nINSERT TESTS\n");
      number_failed += run_test_suite(insert_suite);
    } else if (strcmp(argv[1], "to_lower") == 0) {
      printf("\nTO_LOWER TESTS\n");
      number_failed += run_test_suite(to_lower_suite);
    } else if (strcmp(argv[1], "to_upper") == 0) {
      printf("\nTO_UPPER TESTS\n");
      number_failed += run_test_suite(to_upper_suite);
    } else if (strcmp(argv[1], "trim") == 0) {
      printf("\nTRIM TESTS\n");
      number_failed += run_test_suite(trim_suite);
    }
    // ==== SPRINTF FUNCTION TESTS ====
    else if (strcmp(argv[1], "sprintf") == 0) {
      printf("\nSPRINTF TESTS\n");
      number_failed += run_test_suite(sprintf_suite);
    }
    // ==== SSCANF FUNCTION TESTS ====
    else if (strcmp(argv[1], "sscanf") == 0) {
      printf("\nSSCANF TESTS\n");
      number_failed += run_test_suite(sscanf_suite);
    }
  } else {
    // ==== ADDITIONAL FUNCTION TESTS ====
    printf("\nSTRTOK TESTS\n");
    number_failed += run_test_suite(strtok_suite);
    printf("\nSTRERROR TESTS\n");
    number_failed += run_test_suite(strerror_suite);
    printf("\nSTRNCAT TESTS\n");
    number_failed += run_test_suite(strncat_suite);
    // ==== CALCULATION FUNCTION TESTS ====
    printf("\nSTRCSPN TESTS\n");
    number_failed += run_test_suite(strcspn_suite);
    printf("\nSTRLEN TESTS\n");
    number_failed += run_test_suite(strlen_suite);
    // ==== COMPARE FUNCTION TESTS ====
    printf("\nMEMCMP TESTS\n");
    number_failed += run_test_suite(memcmp_suite);
    printf("\nSTRNCMP TESTS\n");
    number_failed += run_test_suite(strncmp_suite);
    // ==== COPY FUNCTION TESTS ====
    printf("\nMEMCPY TESTS\n");
    number_failed += run_test_suite(memcpy_suite);
    printf("\nMEMSET TESTS\n");
    number_failed += run_test_suite(memset_suite);
    printf("\nSTRNCPY TESTS\n");
    number_failed += run_test_suite(strncpy_suite);
    // ==== SEARCH FUNCTION TESTS ====
    printf("\nMEMCHR TESTS\n");
    number_failed += run_test_suite(memchr_suite);
    printf("\nSTRCHR TESTS\n");
    number_failed += run_test_suite(strchr_suite);
    printf("\nSTRPBRK TESTS\n");
    number_failed += run_test_suite(strpbrk_suite);
    printf("\nSTRRCHR TESTS\n");
    number_failed += run_test_suite(strrchr_suite);
    printf("\nSTRSTR TESTS\n");
    number_failed += run_test_suite(strstr_suite);
    // ==== SPECIAL FUNCTION TESTS ====
    printf("\nINSERT TESTS\n");
    number_failed += run_test_suite(insert_suite);
    printf("\nTO_LOWER TESTS\n");
    number_failed += run_test_suite(to_lower_suite);
    printf("\nTO_UPPER TESTS\n");
    number_failed += run_test_suite(to_upper_suite);
    printf("\nTRIM TESTS\n");
    number_failed += run_test_suite(trim_suite);
    // ==== SPRINTF FUNCTION TESTS ====
    printf("\nSPRINTF TESTS\n");
    number_failed += run_test_suite(sprintf_suite);
    // ==== SSCANF FUNCTION TESTS ====
    printf("\nSSCANF TESTS\n");
    number_failed += run_test_suite(sscanf_suite);
  }
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}