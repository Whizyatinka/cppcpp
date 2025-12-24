from distutils.core import setup, Extension

module = Extension(
    'addList',              
    sources=['Source.cpp']  
)

setup(
    name='addList',
    version='1.0',
    ext_modules=[module],
)