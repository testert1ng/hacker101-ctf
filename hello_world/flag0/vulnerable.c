
int64_t __gmon_start__ = 0;

void _init() {
    int64_t rax1;

    rax1 = __gmon_start__;
    if (rax1) {
        rax1();
    }
    return;
}

int64_t deregister_tm_clones() {
    int64_t rax1;

    rax1 = 7;
    if (1 || (*reinterpret_cast<int32_t*>(&rax1) = 0, *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax1) + 4) = 0, 1)) {
        return rax1;
    } else {
        goto 0;
    }
}

int64_t stdin = 0;

int32_t fun_400590(int64_t rdi);

void read_all_stdin(void* rdi, int64_t rsi, int64_t rdx) {
    void* v4;
    int32_t v5;
    int64_t rax6;
    int32_t eax7;
    int64_t rax8;
    int32_t edx9;

    v4 = rdi;
    v5 = 0;
    while (rax6 = stdin, eax7 = fun_400590(rax6), eax7 != -1) {
        *reinterpret_cast<int32_t*>(&rax8) = v5;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax8) + 4) = 0;
        v5 = static_cast<int32_t>(rax8 + 1);
        edx9 = eax7;
        *reinterpret_cast<signed char*>(reinterpret_cast<int64_t>(v4) + *reinterpret_cast<int32_t*>(&rax8)) = *reinterpret_cast<signed char*>(&edx9);
    }
    return;
}

int64_t puts = 0x400566;

void fun_400560(int64_t rdi, int64_t rsi, int64_t rdx) {
    goto puts;
}

int64_t getenv = 0x400556;

int64_t fun_400550(int64_t rdi) {
    goto getenv;
}

int64_t exit = 0x4005a6;

void fun_4005a0(int64_t rdi) {
    goto exit;
}

int64_t memset = 0x400586;

void fun_400580(void* rdi, int64_t rsi, int64_t rdx) {
    goto memset;
}

int64_t printf = 0x400576;

void fun_400570(int64_t rdi, void* rsi, int64_t rdx) {
    goto printf;
}

int64_t fgetc = 0x400596;

int32_t fun_400590(int64_t rdi) {
    goto fgetc;
}

void _fini() {
    return;
}

void fun_400655() {
    int64_t v1;

    goto v1;
}

int64_t __JCR_END__ = 0;

void exit();

void frame_dummy() {
    int1_t zf1;

    zf1 = __JCR_END__ == 0;
    if (!(zf1 || 1)) {
        exit();
    }
    if (1) 
        goto 0x400658;
    if (1) 
        goto 0x400658;
    goto 0;
}

void print_flags() {
    int64_t rax1;
    int64_t rsi2;
    int64_t rdx3;
    void* rbp4;
    uint32_t eax5;
    unsigned char v6;
    int64_t rbp7;

    rax1 = fun_400550("FLAGS");
    fun_400560(rax1, rsi2, rdx3);
    fun_4005a0(0);
    rbp4 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(__zero_stack_offset()) - 8 - 8 + 8 - 8 + 8 - 8 + 8 - 8);
    fun_400580(reinterpret_cast<int64_t>(rbp4) - 32, 0, 32);
    read_all_stdin(reinterpret_cast<int64_t>(rbp4) - 32, 0, 32);
    eax5 = v6;
    if (*reinterpret_cast<signed char*>(&eax5)) {
        fun_400570("Hello %s!\n", reinterpret_cast<int64_t>(rbp4) - 32, 32);
    } else {
        fun_400560("What is your name?", 0, 32);
    }
    goto rbp7;
}

void __libc_csu_fini() {
    return;
}

int64_t g601010 = 0;

void fun_400556() {
    goto g601010;
}

/* completed.6972 */
signed char completed_6972 = 0;

int64_t __do_global_dtors_aux() {
    int1_t zf1;
    int64_t rax2;

    zf1 = completed_6972 == 0;
    if (zf1) {
        rax2 = deregister_tm_clones();
        completed_6972 = 1;
    }
    return rax2;
}

void fun_400566() {
    goto 0x400540;
}

void __libc_csu_init(int32_t edi, int64_t rsi, int64_t rdx) {
    int32_t r15d4;
    int64_t r14_5;
    int64_t r13_6;
    int64_t rbx7;
    int64_t rdi8;

    r15d4 = edi;
    r14_5 = rsi;
    r13_6 = rdx;
    _init();
    if (!0) {
        *reinterpret_cast<int32_t*>(&rbx7) = 0;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rbx7) + 4) = 0;
        do {
            *reinterpret_cast<int32_t*>(&rdi8) = r15d4;
            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdi8) + 4) = 0;
            *reinterpret_cast<int64_t*>(0x600e08 + rbx7 * 8)(rdi8, r14_5, r13_6);
            ++rbx7;
        } while (1 != rbx7);
    }
    return;
}

void fun_4005a6() {
    goto 0x400540;
}

void fun_400586() {
    goto 0x400540;
}

void fun_400576() {
    goto 0x400540;
}

void fun_400596() {
    goto 0x400540;
}

int64_t __libc_start_main = 0;

void _start() {
    void* rsp1;
    int64_t rdx2;
    int64_t rax3;

    rsp1 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(__zero_stack_offset()) + 8);
    __libc_start_main(0x400710, __return_address(), rsp1, __libc_csu_init, __libc_csu_fini, rdx2, (reinterpret_cast<uint64_t>(rsp1) & 0xfffffffffffffff0) - 8 - 8, rax3);
    __asm__("hlt ");
}
