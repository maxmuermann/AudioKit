# Install XCode template

Run `./install.sh` from the Templates/XCode directory.

# Install Faust

## Install Faust
1. install llvm:
  `brew install --with-clang llvm`
2. Get the lastest faust source. You probably want the faust2 branch:
  ```
  git clone https://github.com/grame-cncm/faust.git
  git checkout faust2
  make
  sudo make install
  ```

## Install Faust architecture template

After successful installation, run `./install.sh` in Templates/faust
