from conan import ConanFile
from conan.tools.files import copy
from conan.tools.layout import basic_layout

class GithubInfoConan(ConanFile):
    name = "github_info"
    version = "1.0.1"

    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = {"shared": False}

    # Especifica qué archivos deben exportarse al directorio de construcción
    exports_sources = "include/*", "lib/*"

    def layout(self):
        basic_layout(self)

    def package(self):
        # Copiar archivos directamente desde la carpeta raíz del proyecto
        copy(self, "*.h", src=f"{self.source_folder}/include", dst=f"{self.package_folder}/include", keep_path=True)
        copy(self, "*.a", src=f"{self.source_folder}/lib", dst=f"{self.package_folder}/lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["github_info"]
