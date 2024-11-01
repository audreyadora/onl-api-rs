#ONL API Bindings
Small wrapper to generate rust bindings for Open Network Linux API (DEB 9)
For use with building custom Open Networking Switch platform

Refer to API docs at: [https://www.opennetlinux.org/](https://www.opennetlinux.org/)

###Building:
- Configure ONL on ONIE capable network switch, use INSTALLED vers. instead of SWI to avoid running on overlay
- SSH & clone to a target user directory, all needed header folders are in /include 
- Run cargo build 
  will output onl_api.rs in /bindings folder



