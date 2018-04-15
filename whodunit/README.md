# Questions

## What's `stdint.h`?

`stdint.h`is a header file in the C standard library introduced in the C99 standard library section 7.18 to allow programmers to write more portable code by providing a set of typedefs that specify exact-width integer types,
together with the defined minimum and maximum allowable values for each type, using macros.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

To specify the width (number of bits) of signed and unsigned int types.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

8, 32, 32 and 16.

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

'B' and 'M'.

## What's the difference between `bfSize` and `biSize`?

bfSize describes the entire file's size in bytes. biSize is the size of the BITMAPINFOHEADER struct in bytes.

## What does it mean if `biHeight` is negative?

The vertical orientation of the image is top-down.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

BiBitCount.

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

If there is no output file to point to

## Why is the third argument to `fread` always `1` in our code?

To read 1 byte at a time

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3

## What does `fseek` do?

Moves to a specified location (start, current, or end) in the file to seek from

## What is `SEEK_C
UR`?

Seeks from currnet location

