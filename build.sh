# Building project
mkdir -p build
cd build
cmake ..
make -j4
if [ $? -ne 0 ]; then
    error "Compilation error"
    exit 3
fi
