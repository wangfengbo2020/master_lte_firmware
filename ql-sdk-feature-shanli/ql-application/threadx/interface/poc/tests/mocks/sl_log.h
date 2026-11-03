/* Match the SDK header's guard so a quoted include next to the production C
 * cannot replace this capture hook with the real printf-based logger. */
#ifndef SL_LOG_H
#define SL_LOG_H
void test_log(const char *tag, const char *format, ...);
#define SL_LOG test_log
#endif
