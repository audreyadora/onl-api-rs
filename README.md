## ONL API RS Bindgen
Small wrapper to generate rust bindings for Open Network Linux API (DEB 9)

For use with building custom Open Networking Switch platform

### Reference:
Refer to API docs at: [https://www.opennetlinux.org/](https://www.opennetlinux.org/)

### Building:
- Configure ONL on ONIE capable network switch, use INSTALLED vers. instead of SWI to avoid running on overlay
- SSH & clone to a target user directory, all needed header folders are in /include 
- Run cargo build
  > [!Note]
  > ONL is based on Debian 9 Strech. In order to compile with rs-bindgen, clang 5.0+ is needed.
  > I used <script src="https://gist.github.com/parsa/0319c9198aca14e4bbea4e3b80cfd4f7.js"></script>
  > to update LLVM tools before running build script
### Output:
Script will output onl_api.rs in /bindings folder



