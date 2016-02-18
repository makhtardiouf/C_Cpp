/* 
$Id: asm_driver.c 7 2007-04-26 08:16:51Z Makhtar $
Driver program for assembly code
It helps setting correctly the client code in protected mode,
ith all segment registers initialized by C
*/

extern int asm_main(void);

int main(void)
{
    int retval = 0;
    retval = asm_main();
    return retval;
}
