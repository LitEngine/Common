#pragma once

#include <iostream>

#if defined(LIT_EXIT_HARD) && LIT_EXIT_HARD
#define LIT_EXIT exit(1);
#else
#define LIT_EXIT
#endif

#define LIT_ASSERT(exp, msg) \
{ if (!(exp)) { std::cerr << "[LIT ASSERT]" << msg << ":" << __FILE__ << ":" << __LINE__ << std::endl; LIT_EXIT }}

#define LIT_ENSURE(constraint) \
{ if (!(constraint)) { std::cerr << "[Constraint violated] \"" << #constraint << "\" is false" << std::endl << \
"Location: " << __FILE__ << ":" << __LINE__ << std::endl << std::endl; LIT_EXIT }}

#define LIT_ENSURE_EQ(expr, val) \
{ auto expr_res = (expr); auto val_res = (val);\
if (expr_res != val_res) {std::cout << "[Constraint violated] " << #expr << " != " << #val << std::endl << \
"Values are " << expr_res << " and " << val_res << std::endl <<\
"Location: " << __FILE__ << ":" << __LINE__ << std::endl << std::endl; LIT_EXIT }}

#define LIT_ENSURE_BETWEEN(expr, val_low, val_high) \
{ auto expr_res = (expr); auto val_low_res = (val_low); auto val_high_res = (val_high);\
if (expr_res < val_low_res || expr_res > val_high_res) \
{ std::cout << "[Constraint violated] " << #expr << " is out of range [" \
<< #val_low << ", " << #val_high << "]" << std::endl \
<< "Values are " << expr_res << ", " << val_low_res << " and " << val_high_res << std::endl <<\
"Location: " << __FILE__ << ":" << __LINE__ << std::endl << std::endl; LIT_EXIT }}
