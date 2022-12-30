#pragma once

#define OC_FILE                                                                \
  (strrchr(__builtin_FILE(), '\\') ? strrchr(__builtin_FILE(), '\\') + 1       \
                                   : __builtin_FILE())

#define OC_LINE __builtin_LINE()
