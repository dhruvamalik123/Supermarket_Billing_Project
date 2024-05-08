#include <quickmail.h>
#include <iostream>
#pragma comment(lib, "libquickmaillight.dll.a")

int main()
{
    quickmail_initialize();
    quickmail mailobj = quickmail_create("dhruvamalik.05@gmail.com", "libquickmail test e-mail");
	
    quickmail_set_body(mailobj, "This is a test e-mail.\nThis mail was sent using libquickmail.");
	quickmail_add_to(mailobj, "dhruvamalik2003@gmail.com");
	const char *errmsg = quickmail_send_secure(mailobj, "smtp.gmail.com", 465, "dhruvamalik.05@gmail.com", "Pleovaldez");
    if (errmsg != NULL) {
        fprintf(stderr, "Error sending e-mail: %s\n", errmsg);
    }

    quickmail_destroy(mailobj);
}
