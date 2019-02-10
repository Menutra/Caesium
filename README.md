# Caesium
Ubuntu, using Clang

    sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y
    wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | sudo apt-key add -

You need to modify the below command for your version of ubuntu - see https://apt.llvm.org/

    Ubuntu 14.04 (Trusty)

    sudo add-apt-repository "deb https://apt.llvm.org/trusty/ llvm-toolchain-trusty 6.0 main"

    Ubuntu 16.04 (Xenial)

    sudo add-apt-repository "deb https://apt.llvm.org/xenial/ llvm-toolchain-xenial 6.0 main"

    Ubuntu 18.04 (Bionic)

    sudo add-apt-repository "deb https://apt.llvm.org/bionic/ llvm-toolchain-bionic 6.0 main"

    sudo apt-get update

    sudo apt-get install aptitude -y

    sudo aptitude install -y -o Aptitude::ProblemResolver::SolutionCost='100*canceled-actions,200*removals' build-essential clang-6.0 libstdc++-7-dev git libboost-all-dev python-pip

    sudo pip install cmake

    export CC=clang-6.0

    export CXX=clang++-6.0

    git clone https://github.com/Menutra/Caesium

    cd Caesium

    mkdir build

    cd build

    cmake ..

    make

The binaries will be in the src folder when you are complete.

    cd src
    ./Lithed --version

Windows
Prerequisites

    Install Visual Studio 2017 Community Edition
    When installing Visual Studio, it is required that you install Desktop development with C++
    Install the latest version of Boost - Currently Boost 1.68.

Building

    From the start menu, open 'x64 Native Tools Command Prompt for vs2017'.
    cd <your_caesium_directory>
    mkdir build
    cd build
    set PATH="C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin";%PATH%
    cmake -G "Visual Studio 15 2017 Win64" .. -DBOOST_ROOT=C:/local/boost_1_68_0

If you have errors on this step about not being able to find the following static libraries, you may need to update your cmake. Open 'Visual Studio Installer' and click 'Update'.

    MSBuild Lithe.sln /p:Configuration=Release /m

The binaries will be in the src/Release folder when you are complete.

    cd src
    cd Release
    Lithed.exe --version
