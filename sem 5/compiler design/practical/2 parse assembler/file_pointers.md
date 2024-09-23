**FILE POINTERS**

1) each file has 2 associated pointers known as file pointers

2) one is the input pointer, or get pointer
other is output pointer or put pointer

3) pointers are used to move through the files while reading or writing

4) input pointer : used to read contents of a file

5) output pointer : used to writing to a file

6) file can be opened in 3 modes
    a) reading mode
    b) writing mode : writes after deleting the existing data
    c) append mode : adding more data to existing data


**we can cprovide control on our own using following fucntions:**

1) Seekg() : moes get pointer(input pointer) to specified location.

2) Seekp() : moves put pointer(output pointer) to specified location.

3) tellg() : gives the current position of input pointer.

4) Tellp() : gives the current position of put pointer.