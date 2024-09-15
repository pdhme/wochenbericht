#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <hash-table.h>
#include <http.h>

short api(HTTP_REQUEST_HANDLER_ARGUMENTS) {

	return 0;
}
short add_wrong(HTTP_REQUEST_HANDLER_ARGUMENTS) {

	return 0;
}
short add_correct(HTTP_REQUEST_HANDLER_ARGUMENTS) {

	return 0;
}

short home(HTTP_REQUEST_HANDLER_ARGUMENTS) {
	return http_respond(HTTP_PASS_REQUEST_HANDLER_ARGUMENTS, ".");
}

int main(int argc, char** argv) {
	if (argc == 1) return 1;
	http_server server = {.port = "8080", .use_tls = 0, .multi_thread = 0};
	server.request_handlers = hash_table_init(10000);
	ht_set(server.request_handlers, "/ ", &home);
	http_server_run(&server);
	return 0;
}
