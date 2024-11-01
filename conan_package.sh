rm -rf build

conan install . -s build_type=Release -s compiler.cppstd=23 --output-folder=build --build missing

cmake --preset conan-release

cmake --build build

rm -rf package/include
rm -rf package/lib

mkdir package/include
mkdir package/lib

cp ./build/github_info/libgithub_info.a package/lib/libgithub_info.a

cp ./github_info/include/github_info.h package/include/github_info.h

cp ./github_info/include/github_info_interface.h package/include/github_info_interface.h

cp ./github_info/include/github_repository.h package/include/github_repository.h

cp ./github_info/include/github_user.h package/include/github_user.h

cp ./github_info/include/github_user.h package/include/github_error.h

conan create ./package --user juanjofp --channel develop --build missing
