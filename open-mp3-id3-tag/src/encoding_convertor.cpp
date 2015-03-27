/*
Copyright (C) 2012 Carlos Tse <copperoxide@gmail.com>

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "encoding_convertor.h"

EncodingConvertor::EncodingConvertor(const char* fromCharset/*, const char* toCharset*/)
{
	_fromCharset = fromCharset;

	/*
	_toCharset = toCharset;
	conv = iconv_open(toCharset, fromCharset);

	if (errno != 0) {
		if (errno == EINVAL)
			printf("conversion from %s to %s is not supported.\n", fromCharset, toCharset);
		else
			printf("iconv_open failure: %s\n", strerror(errno));
	}
	*/
}

EncodingConvertor::~EncodingConvertor()
{
//	if (errno != 0 && iconv_close(conv) != 0) {
//		printf("iconv_close failed: %s\n", strerror(errno));
//	}
}

void EncodingConvertor::debugHex(const char *header, const char *content)
{
	printf("%s: %s (", header, content);

	size_t len = strlen(content);
	for (unsigned int i = 0; i < len; i++) {
		printf("%02X", (unsigned char) content[i]);
		if (i < len - 1)
			printf (" ");
	}
	printf (") \n");
}

QString EncodingConvertor::convert(const char *input) const
{
	if (input == NULL || strlen(input) == 0)
		return QString("");

	return QTextCodec::codecForName(_fromCharset)->toUnicode(input);
}

/*
char *EncodingConvertor::convert(const char *input) const
{
	if (errno != 0)
		return NULL;

	size_t outleft, converted = 0;
	char *output, *outbuf, *tmp;

	size_t inleft = strlen(input);
	const char *inbuf = input;

	// in average UTF-8 use 3 bytes to store one Chinese word
	size_t outlen = inleft * 3;

	// we allocate 4 bytes more than what we need for nul-termination...
	if (!(output = (char *) malloc(outlen + 4))) {
//		iconv_close(cd);
		return NULL;
	}

	while(1) {
		errno = 0;
		outbuf = output + converted;
		outleft = outlen - converted;

		converted = iconv(conv, (char **) &inbuf, &inleft, &outbuf, &outleft);
		if (converted != (size_t) -1 || errno == EINVAL) {
			// An incomplete multibyte sequence has been encoun­tered in the input.
			// We'll just truncate it and ignore it.
			break;
		}

		if (errno != E2BIG) {
			// An invalid multibyte sequence has been encountered in the input.
			// Bad input, we can't really recover from this.
//			iconv_close(cd);
			free(output);
			return NULL;
		}

		// E2BIG: There is not sufficient room at *outbuf.
		// We just need to grow our outbuffer and try again.
		converted = outbuf - output;
		outlen += inleft * 2 + 8;

		if (!(tmp = (char *) realloc(output, outlen + 4))) {
//			iconv_close(cd);
			free(output);
			return NULL;
		}

		output = tmp;
		outbuf = output + converted;
	}

	// flush the iconv conversion
	iconv(conv, NULL, NULL, &outbuf, &outleft);
//	iconv_close(cd);

	// Note: not all charsets can be nul-terminated with a single nul byte.
	// UCS2, for example, needs 2 nul bytes and
	// UCS4 needs 4
	// nul-terminate the string
	memset(outbuf, 0, 4);

	return output;
}
*/

