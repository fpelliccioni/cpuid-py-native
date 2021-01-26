#!/usr/bin/env python

# 
# Copyright (c) 2017-2021 Fernando Pelliccioni
# 

import sys
from setuptools import setup
from setuptools.extension import Extension

PKG_NAME = 'cpuid_native'
VERSION = '0.0.7'
SYSTEM = sys.platform

# ------------------------------------------------

from sys import platform
# if platform == "linux" or platform == "linux2":
#     # linux
# elif platform == "darwin":
#     # OS X
# elif platform == "win32":
#     # Windows...


extensions = [
	Extension('cpuid_native',
    	sources = ['cpuidmodule.cpp'],
    ),
]

setup(
    name=PKG_NAME,
    version=VERSION,

    description='x86 cpuid native API',
    long_description='x86 cpuid native API',
    url='https://github.com/fpelliccioni/cpuid-py-native',

    # Author details
    author='Fernando Pelliccioni',
    author_email='fpelliccioni@gmail.com',

    # Choose your license
    license='MIT',

    # See https://pypi.python.org/pypi?%3Aaction=list_classifiers
    classifiers=[
        # How mature is this project? Common values are
        #   3 - Alpha
        #   4 - Beta
        #   5 - Production/Stable
        'Development Status :: 3 - Alpha',

        # Indicate who your project is intended for
        'Intended Audience :: Developers',
        'Topic :: Software Development :: Build Tools',

        # Pick your license as you wish (should match "license" above)
        'License :: OSI Approved :: MIT License',

        'Programming Language :: C++',
        'Programming Language :: Python :: 2',
        'Programming Language :: Python :: 2.7',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.4',
        'Programming Language :: Python :: 3.5',
        'Programming Language :: Python :: 3.6',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
    ],

    # What does your project relate to?
    keywords='intel amd cpuid x86',

    extras_require={
        'dev': ['check-manifest'],
        'test': ['coverage'],
    },

    ext_modules = extensions,
)
