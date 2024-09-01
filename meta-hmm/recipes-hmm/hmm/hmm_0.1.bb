DESCRIPTION = "heap memory manager build recipe"
PR = "r1"

do_build() {
             cd ${PROJDIR}
             ${CC} ${CFLAGS} -c main.c -o main.o
             ${CC} ${CFLAGS} -c  ${PROJDIR}/lib/myalloc.c -o ${PROJDIR}/lib/myalloc.o
             ${AR} rcs ${PROJDIR}/lib/libhmm.a ${PROJDIR}/lib/myalloc.o
             ${CC} ${CFLAGS} -shared -o ${PROJDIR}/lib/libhmm.so ${PROJDIR}/lib/myalloc.o
             ${CC} ${CFLAGS} main.o ${PROJDIR}/lib/libhmm.so -o main
             echo "=== Build Done ==="
}

do_clean() {
        cd ${PROJDIR}
        rm *.o ./lib/*.o ./lib/*.a ./lib/*.so
        echo "clean done"
}

addtask clean before build
