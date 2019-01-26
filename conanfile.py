from conans import ConanFile, CMake, tools


class UfuzzerConan(ConanFile):
    name = "ufuzzer"
    version = "0.0.1"
    license = "Apache License Version 2.0"
    author = "ukhegg ukhegg@gmail.com"
    url = "https://github.com/ukhegg/ufuzzer.git"
    description = "fuzzing framework"
    topics = ("fuzzing", "cpp")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = "shared=True"
    generators = "cmake"
    build_requires = "Catch/1.12.1@bincrafters/stable", \
                     "gsl_microsoft/2.0.0@bincrafters/stable"

    def source(self):
        self.run("git clone -b {} {} .".format(self.version, self.url))
        self.run("cd hello && git checkout static_shared")

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        self.copy("*.h", dst="include", src="hello")
        self.copy("*hello.lib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.dylib", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["ufuzzer"]
