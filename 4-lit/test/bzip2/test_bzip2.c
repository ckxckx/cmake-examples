/*
 * RUN: %{encode} 'This is a test' > %t1.actual
 * RUN: echo "(base64): VGhpcyBpcyBhIHRlc3Q=" > %t1.expected
 * RUN: echo "(bzip2): QlpoMTFBWSZTWSDsdxUAAAGTgEAABAAiYAwAIA==" >> %t1.expected
 * RUN: diff %t1.actual %t1.expected
 */
