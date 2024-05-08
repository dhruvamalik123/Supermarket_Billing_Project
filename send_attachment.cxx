
#include <quickmail.h>
#include <iostream>
#pragma comment(lib, "libquickmail.dll.a")

int main()
{

    quickmail_initialize();
    quickmail mailobj = quickmail_create("dhruv.5@rediffmail.com", "libquickmail test e-mail");
	
    quickmail_set_body(mailobj, "This is a test e-mail.\nThis mail was sent using libquickmail.");
	quickmail_add_to(mailobj, "dhruvamalik2003@gmail.com");
	const char *errmsg = quickmail_send(mailobj, "pop.rediffmail.com", 110, "dhruv.5@rediffmail.com", "ddapsmalik");
    if (errmsg != NULL) {
        fprintf(stderr, "Error sending e-mail: %s\n", errmsg);
    }

    quickmail_destroy(mailobj);
}