#include <usb_names.h>

#define MANUFACTURER_NAME          \
	{                          \
		'L', 'Y', 'T', 'R', 'I', 'X' \
	}
#define MANUFACTURER_NAME_LEN 6

#define PRODUCT_NAME                                                            \
	{                                                                       \
		'M', '4', 'L', '-', 'C', 'T', 'R', 'L' \
	}
#define PRODUCT_NAME_LEN 8

#define SERIAL_NUMBER                                            \
	{                                                        \
		'-', 'M', '4', 'L', '-', 'C', 'T', 'R', 'L','-' \
	}
#define SERIAL_NUMBER_LEN 10

struct usb_string_descriptor_struct usb_string_manufacturer_name = {
	2 + MANUFACTURER_NAME_LEN * 2,
	3,
	MANUFACTURER_NAME};

struct usb_string_descriptor_struct usb_string_product_name = {
	2 + PRODUCT_NAME_LEN * 2,
	3,
	PRODUCT_NAME};

struct usb_string_descriptor_struct usb_string_serial_number = {
	2 + SERIAL_NUMBER_LEN * 2,
	3,
	SERIAL_NUMBER};