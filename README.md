## ONL API RS Bindgen
Small wrapper to generate rust bindings for Open Network Linux API (DEB 9)

For use with building custom Open Networking Switch platform

### Reference:
Refer to API docs at: [https://www.opennetlinux.org/](https://www.opennetlinux.org/)
### Configuring ONL:
- Update the /etc/apt/sources.list.d/multistrap-debian.list with the archive version for Stretch:
   [https://debiansupport.com/mirrors/](https://debiansupport.com/mirrors/)
```
  deb http://archive.debian.org/debian/ stretch main contrib non-free
  deb http://archive.debian.org/debian/ stretch-proposed-updates main contrib non-free
  deb http://archive.debian.org/debian-security stretch/updates main contrib non-free
```
- Install apt-transport-https and update apt
- Install git
- rs-bindgen requires clang 5.0+. I used [this script](https://gist.github.com/parsa/0319c9198aca14e4bbea4e3b80cfd4f7) to update to clang/LLVM 8 before building with cargo. You might need to edit script with --allow-unauthenticated flags to get it to install
### Building:
- Install ONL on ONIE capable network switch or VM, use INSTALLED vers. instead of SWI to avoid running on overlay
- SSH & clone to a target user directory, all needed header folders are in /include 
- Run cargo build
### Output:
Script will output onl_api.rs in /bindings folder



