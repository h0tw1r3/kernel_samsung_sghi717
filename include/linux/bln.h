/* include/linux/bln.h */

#ifndef _LINUX_BLN_H
#define _LINUX_BLN_H

struct bln_implementation {
    bool (*enable)(void);
    bool (*disable)(void);
};

void register_bln_implementation(struct bln_implementation *imp);
bool bln_is_ongoing(void);
#endif
