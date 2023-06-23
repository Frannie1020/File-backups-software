# file-backups-software

💡Create a file backup software. Contain at least the following basic functions:

 Backup of data (packing, compression of original data)

 Data restoration (decompression, unpacking of backup data)

 Basic user interaction interface

 Checking of the backed up files

💡In addition to this, the file backup software can also have a number of optional features:

 Cloud backup: uploads data to a server over the network into a cloud backup.

 Encrypted backup: allows the user to set a password for the backup data when backing it up and when decompressing it, the password needs to be entered.

 Automatic Backup: Allows users to set up automatic backups, such as a backup of a specified file or folder to a specified directory at 8:00 pm every day.

 Other custom functions.

The user interface is implemented via the command line and the packing and unpacking interface is obtained by outputting the corresponding prompts. Firstly, the corresponding function numbers 0, 1 and 2 are prompted, corresponding to exit, pack and unpack respectively. Then the switch case selection statement determines the user input and calls the pack and unpack program to run. The interface is as follows.

![image](https://github.com/Frannie1020/file-backups-software/assets/137517674/c307c3bc-2046-4d78-aec9-4d43d442829c)

Compression and decompression is achieved through specific prompts, on the command line, with the following interface:

![image](https://github.com/Frannie1020/file-backups-software/assets/137517674/3897da33-8c6a-4685-98f4-6b296719cfd9)

Use case diagram:

![image](https://github.com/Frannie1020/file-backups-software/assets/137517674/b802f162-8666-4185-b30b-651098af3b78)

Class diagram:

![image](https://github.com/Frannie1020/file-backups-software/assets/137517674/c94c3e73-40b1-4a3d-ab9f-319b20556806)

Unpacking module：

![image](https://github.com/Frannie1020/file-backups-software/assets/137517674/831386a8-a1ac-4d78-8779-52e8f21ad609)

Compression and decompression module：

![image](https://github.com/Frannie1020/file-backups-software/assets/137517674/d9737b3a-80e6-4052-9768-949168195373)

Validation module：
![image](https://github.com/Frannie1020/file-backups-software/assets/137517674/8687234b-f1b2-4715-973f-e667761245e5)

💡Functional tests

Packing and Unpacking Module

1: Files to be packaged

![image](https://github.com/Frannie1020/file-backups-software/assets/137517674/eed6ff4e-cd84-486f-999a-595ba3e7b851)

2: The files generated after packing are as follows: zyj.txt is the index file, zyj.KCS1086 is the packed file

![image](https://github.com/Frannie1020/file-backups-software/assets/137517674/e8b0cbec-f2b5-4079-bb1c-b60bf8dcb87c)

3：Packed as follows：

![image](https://github.com/Frannie1020/file-backups-software/assets/137517674/ef25f6c1-fc86-4493-bdd2-4b3d628486c2)

4：Unpack the file as follows：

![image](https://github.com/Frannie1020/file-backups-software/assets/137517674/d8619fe9-51c9-493d-9db1-919ba8eeee81)

5：Unpack the file as follows：

![image](https://github.com/Frannie1020/file-backups-software/assets/137517674/b948325a-60b5-494e-8bf9-d9752ae21d4d)

💡Compression and decompression module

6: Compression

![image](https://github.com/Frannie1020/file-backups-software/assets/137517674/98f530d5-f5d4-4f8a-9690-bfac0aaf19e7)

7: After compression

![image](https://github.com/Frannie1020/file-backups-software/assets/137517674/a80eba5b-9749-46d1-ad02-be511500b07a)

8: Decompression

![image](https://github.com/Frannie1020/file-backups-software/assets/137517674/3a150220-3561-45c5-acef-f22689541b14)

9: Unzip the file to verify

![image](https://github.com/Frannie1020/file-backups-software/assets/137517674/ee05ae58-42c5-425a-bcf5-a0691c888d92)

In conclusion, the command line interface of the file backup software allows the user to compress and decompress, pack and unpack files. Packing and unpacking can be achieved by indexing files to create unique marker information for easy comparison and searching. Compression and decompression are greatly enhanced by Huffman coding and Huffman tree construction, which helps to speed up the storage of compressed and decompressed file information.
