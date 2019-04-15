Building The Library
=================================

This document describes how to build Botan on Unix/POSIX and Windows
systems. The POSIX oriented descriptions should apply to most
common Unix systems (including OS X), along with POSIX-ish systems
like BeOS, QNX, and Plan 9. Currently, systems other than Windows and
POSIX (such as VMS, MacOS 9, OS/390, OS/400, ...) are not supported by
the build system, primarily due to lack of access. Please contact the
maintainer if you would like to build Botan on such a system.

Botan's build is controlled by configure.py, which is a `Python
<https://www.python.org>`_ script. Python 2.6 or later is required.

.. highlight:: none

For the impatient, this works for most systems::

  $ ./configure.py [--prefix=/some/directory]
  $ make
  $ make install

Or using ``nmake``, if you're compiling on Windows with Visual C++. On
platforms that do not understand the '#!' convention for beginning
script files, or that have Python installed in an unusual spot, you
might need to prefix the ``configure.py`` command with ``python`` or
``/path/to/python``::

  $ python ./configure.py [arguments]

Configuring the Build
---------------------------------

The first step is to run ``configure.py``, which is a Python script
that creates various directories, config files, and a Makefile for
building everything. This script should run under a vanilla install of
Python 2.6, 2.7, or 3.x.

The script will attempt to guess what kind of system you are trying to
compile for (and will print messages telling you what it guessed).
You can override this process by passing the options ``--cc``,
``--os``, and ``--cpu``.

You can pass basically anything reasonable with ``--cpu``: the script
knows about a large number of different architectures, their
sub-models, and common aliases for them. You should only select the
64-bit version of a CPU (such as "sparc64" or "mips64") if your
operating system knows how to handle 64-bit object code - a 32-bit
kernel on a 64-bit CPU will generally not like 64-bit code.

By default the script tries to figure out what will work on your
system, and use that. It will print a display at the end showing which
algorithms have and have not been enabled. For instance on one system
we might see lines like::

   INFO: Skipping (dependency failure): certstor_sqlite3 sessions_sqlite3
   INFO: Skipping (incompatible CPU): aes_power8
   INFO: Skipping (incompatible OS): darwin_secrandom getentropy win32_stats
   INFO: Skipping (incompatible compiler): aes_armv8 pmull sha1_armv8 sha2_32_armv8
   INFO: Skipping (no enabled compression schemes): compression
   INFO: Skipping (requires external dependency): bearssl boost bzip2 lzma openssl sqlite3 tpm zlib

The ones that are skipped because they are require an external
dependency have to be explicitly asked for, because they rely on third
party libraries which your system might not have or that you might not
want the resulting binary to depend on. For instance to enable zlib
support, add ``--with-zlib`` to your invocation of ``configure.py``.
All available modules can be listed with ``--list-modules``.

You can control which algorithms and modules are built using the
options ``--enable-modules=MODS`` and ``--disable-modules=MODS``, for
instance ``--enable-modules=zlib`` and ``--disable-modules=xtea,idea``.
Modules not listed on the command line will simply be loaded if needed
or if configured to load by default. If you use ``--minimized-build``,
only the most core modules will be included; you can then explicitly
enable things that you want to use with ``--enable-modules``. This is
useful for creating a minimal build targeting to a specific
application, especially in conjunction with the amalgamation option;
see :ref:`amalgamation`.

For instance::

 $ ./configure.py --minimized-build --enable-modules=rsa,eme_oaep,emsa_pssr

will set up a build that only includes RSA, OAEP, PSS along with any
required dependencies. Note that a minimized build does not by default
include any random number generator, which is needed for example to
generate keys, nonces and IVs. See :doc:`rng` on which random number
generators are available.

The option ``--module-policy=POL`` enables modules required by and
disables modules prohibited by a text policy in ``src/build-data/policy``.
Additional modules can be enabled if not prohibited by the policy.
Currently available policies include ``bsi``, ``nist`` and ``modern``::

 $ ./configure.py --module-policy=bsi --enable-modules=tls,xts

Cross Compiling
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Cross compiling refers to building software on one type of host (say Linux
x86-64) but creating a binary for some other type (say MinGW x86-32). This is
completely supported by the build system. To extend the example, we must tell
`configure.py` to use the MinGW tools::

 $ ./configure.py --os=mingw --cpu=x86_32 --cc-bin=i686-w64-mingw32-g++ --ar=i686-w64-mingw32-ar
 ...
 $ make
 ...
 $ file botan.exe
 botan.exe: PE32 executable (console) Intel 80386, for MS Windows

You can also specify the alternate tools by setting the `CXX` and `AR`
environment variables (instead of the `--cc-bin` and `--ar-command` options), as
is commonly done with autoconf builds.

On Unix
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The basic build procedure on Unix and Unix-like systems is::

   $ ./configure.py [--enable-modules=<list>] [--cc=CC]
   $ make
   $ ./botan-test

If that fails with an error about not being able to find libbotan.so,
you may need to set ``LD_LIBRARY_PATH``::

   $ LD_LIBRARY_PATH=. ./botan-test

If the tests look OK, install::

   $ make install

On Unix systems the script will default to using GCC; use ``--cc`` if
you want something else. For instance use ``--cc=icc`` for Intel C++
and ``--cc=clang`` for Clang.

The ``make install`` target has a default directory in which it will
install Botan (typically ``/usr/local``). You can override this by
using the ``--prefix`` argument to ``configure.py``, like so::

   $ ./configure.py --prefix=/opt <other arguments>

On some systems shared libraries might not be immediately visible to
the runtime linker. For example, on Linux you may have to edit
``/etc/ld.so.conf`` and run ``ldconfig`` (as root) in order for new
shared libraries to be picked up by the linker. An alternative is to
set your ``LD_LIBRARY_PATH`` shell variable to include the directory
that the Botan libraries were installed into.

On macOS
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

A build on macOS works much like that on any other Unix-like system.

To build a universal binary for macOS, you need to set some additional
build flags. Do this with the `configure.py` flag `--cc-abi-flags`::

  --cc-abi-flags="-force_cpusubtype_ALL -mmacosx-version-min=10.4 -arch i386 -arch ppc"

On Windows
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. note::

   The earliest versions of Windows supported are Windows 7 and Windows 2008 R2

You need to have a copy of Python installed, and have both Python and
your chosen compiler in your path. Open a command shell (or the SDK
shell), and run::

   $ python configure.py --cc=msvc --os=windows
   $ nmake
   $ botan-test.exe
   $ nmake install

Botan supports the nmake replacement `Jom <https://wiki.qt.io/Jom>`_
which enables you to run multiple build jobs in parallel.

For MinGW, use::

   $ python configure.py --cc=gcc --os=mingw
   $ make

By default the install target will be ``C:\botan``; you can modify
this with the ``--prefix`` option.

When building your applications, all you have to do is tell the
compiler to look for both include files and library files in
``C:\botan``, and it will find both. Or you can move them to a
place where they will be in the default compiler search paths (consult
your documentation and/or local expert for details).


For iOS using XCode
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

For iOS, you typically build for 3 architectures: armv7 (32 bit, older
iOS devices), armv8-a (64 bit, recent iOS devices) and x86_64 for
the iPhone simulator. You can build for these 3 architectures and then
create a universal binary containing code for all of these
architectures, so you can link to Botan for the simulator as well as
for an iOS device.

To cross compile for armv7, configure and make with::

   $ ./configure.py --os=ios --prefix="iphone-32" --cpu=armv7 --cc=clang \
                    --cc-abi-flags="-arch armv7"
   xcrun --sdk iphoneos make install

To cross compile for armv8-a, configure and make with::

   $ ./configure.py --os=ios --prefix="iphone-64" --cpu=armv8-a --cc=clang \
                    --cc-abi-flags="-arch arm64"
   xcrun --sdk iphoneos make install

To compile for the iPhone Simulator, configure and make with::

   $ ./configure.py --os=ios --prefix="iphone-simulator" --cpu=x86_64 --cc=clang \
                    --cc-abi-flags="-arch x86_64"
   xcrun --sdk iphonesimulator make install

Now create the universal binary and confirm the library is compiled
for all three architectures::

   $ xcrun --sdk iphoneos lipo -create -output libbotan-2.a \
                  iphone-32/lib/libbotan-2.a \
                  iphone-64/lib/libbotan-2.a \
                  iphone-simulator/lib/libbotan-2.a
   $ xcrun --sdk iphoneos lipo -info libbotan-2.a
   Architectures in the fat file: libbotan-2.a are: armv7 x86_64 armv64

The resulting static library can be linked to your app in Xcode.

For Android
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Instructions for building the library on Android can be found
`here <https://www.danielseither.de/blog/2013/03/building-the-botan-library-for-android/>`_.

Emscripten (WebAssembly)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

To build for WebAssembly using Emscripten, try::

  CXX=em++ ./configure.py --cc=clang --cpu=llvm --os=emscripten
  make

This will produce bitcode files ``botan-test.bc`` and ``botan.bc``
along with a static archive ``libbotan-2.a`` which can linked with
other modules.  To convert the tests into a WASM file which can be
executed on a browser, use::

  em++ -s ALLOW_MEMORY_GROWTH=1 -s DISABLE_EXCEPTION_CATCHING=0 -s WASM=1 \
     --preload-file src/tests/data botan-test.bc -o botan-test.html

Supporting Older Distros
^^^^^^^^^^^^^^^^^^^^^^^^^

Some "stable" distributions, notably RHEL/CentOS, ship very obsolete
versions of binutils, which do not support more recent CPU instructions.
As a result when building you may receive errors like::

   Error: no such instruction: `sha256rnds2 %xmm0,%xmm4,%xmm3'

Depending on how old your binutils is, you may need to disable BMI2,
AVX2, SHA-NI, and/or RDSEED. These can be disabled by passing the
flags ``--disable-bmi2``, ``--disable-avx2``, ``--disable-sha-ni``,
and ``--disable-rdseed`` to ``configure.py``.

Other Build-Related Tasks
----------------------------------------

.. _building_docs:

Building The Documentation
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

There are two documentation options available, Sphinx and Doxygen.
Sphinx will be used if ``sphinx-build`` is detected in the PATH, or if
``--with-sphinx`` is used at configure time. Doxygen is only enabled
if ``--with-doxygen`` is used. Both are generated by the makefile
target ``docs``.


.. _amalgamation:

The Amalgamation Build
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

You can also configure Botan to be built using only a single source file; this
is quite convenient if you plan to embed the library into another application.

To generate the amalgamation, run ``configure.py`` with whatever
options you would ordinarily use, along with the option
``--amalgamation``. This will create two (rather large) files,
``botan_all.h`` and ``botan_all.cpp``, plus (unless the option
``--single-amalgamation-file`` is used) also some number of files like
``botan_all_aesni.cpp`` and ``botan_all_sse2.cpp`` which need to be
compiled with the appropriate compiler flags to enable that
instruction set. The ISA specific files are only generated if there is
code that requires them, so you can simplify your build. The
``--minimized-build`` option (described elsewhere in this documentation)
is also quite useful with the amalgamation.

Whenever you would have included a botan header, you can then include
``botan_all.h``, and include ``botan_all.cpp`` along with the rest of
the source files in your build. If you want to be able to easily
switch between amalgamated and non-amalgamated versions (for instance
to take advantage of prepackaged versions of botan on operating
systems that support it), you can instead ignore ``botan_all.h`` and
use the headers from ``build/include`` as normal.

You can also build the library using Botan's build system (as normal)
but utilizing the amalgamation instead of the individual source files
by running something like ``./configure.py --amalgamation && make``.
This is essentially a very simple form of link time optimization;
because the entire library source is visible to the compiler, it has
more opportunities for interprocedural optimizations.
Additionally, amalgamation builds usually have significantly shorter
compile times for full rebuilds.

Modules Relying on Third Party Libraries
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Currently ``configure.py`` cannot detect if external libraries are
available, so using them is controlled explicitly at build time
by the user using

 - ``--with-bzip2`` enables the filters providing bzip2 compression and
   decompression. Requires the bzip2 development libraries to be installed.

 - ``--with-zlib`` enables the filters providing zlib compression and
   decompression. Requires the zlib development libraries to be installed.

 - ``--with-lzma`` enables the filters providing lzma compression and
   decompression. Requires the lzma development libraries to be installed.

 - ``--with-sqlite3`` enables using sqlite3 databases in various contexts
   (TLS session cache, PSK database, etc).

 - ``--with-openssl`` adds an engine that uses OpenSSL for some ciphers, hashes,
   and public key operations. OpenSSL 1.0.2 or later is supported. LibreSSL can
   also be used.

 - ``--with-tpm`` adds support for using TPM hardware via the TrouSerS library.

 - ``--with-boost`` enables using some Boost libraries. In particular
   Boost.Filesystem is used for a few operations (but on most platforms, a
   native API equivalent is available), and Boost.Asio is used to provide a few
   extra TLS related command line utilities.

Multiple Builds
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

It may be useful to run multiple builds with different configurations.
Specify ``--with-build-dir=<dir>`` to set up a build environment in a
different directory.

Setting Distribution Info
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The build allows you to set some information about what distribution
this build of the library comes from.  It is particularly relevant to
people packaging the library for wider distribution, to signify what
distribution this build is from. Applications can test this value by
checking the string value of the macro ``BOTAN_DISTRIBUTION_INFO``. It
can be set using the ``--distribution-info`` flag to ``configure.py``,
and otherwise defaults to "unspecified". For instance, a `Gentoo
<https://www.gentoo.org>`_ ebuild might set it with
``--distribution-info="Gentoo ${PVR}"`` where ``${PVR}`` is an ebuild
variable automatically set to a combination of the library and ebuild
versions.

Local Configuration Settings
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

You may want to do something peculiar with the configuration; to
support this there is a flag to ``configure.py`` called
``--with-local-config=<file>``. The contents of the file are
inserted into ``build/build.h`` which is (indirectly) included
into every Botan header and source file.

Enabling or Disabling Use of Certain OS Features
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Botan uses compile-time flags to enable or disable use of certain operating
specific functions. You can also override these at build time if desired.

The default feature flags are given in the files in ``src/build-data/os`` in the
``target_features`` block. For example Linux defines flags like ``proc_fs``,
``getauxval``, and ``sockets``.  The ``configure.py`` option
``--list-os-features`` will display all the feature flags for all operating
system targets.

To disable a default-enabled flag, use ``--without-os-feature=feat1,feat2,...``

To enable a flag that isn't otherwise enabled, use ``--with-os-feature=feat``.
For example, modern Linux systems support the ``getentropy`` call, but it is not
enabled by default because many older systems lack it. However if you know you
will only deploy to recently updated systems you can use
``--with-os-feature=getentropy`` to enable it.

A special case if dynamic loading, which applications for certain environments
will want to disable. There is no specific feature flag for this, but
``--disable-modules=dyn_load`` will prevent it from being used.

.. note:: Disabling ``dyn_load`` module will also disable the PKCS #11
          wrapper, which relies on dynamic loading.

Configuration Parameters
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

There are some configuration parameters which you may want to tweak
before building the library. These can be found in ``build.h``. This
file is overwritten every time the configure script is run (and does
not exist until after you run the script for the first time).

Also included in ``build/build.h`` are macros which let applications
check which features are included in the current version of the
library. All of them begin with ``BOTAN_HAS_``. For example, if
``BOTAN_HAS_BLOWFISH`` is defined, then an application can include
``<botan/blowfish.h>`` and use the Blowfish class.

``BOTAN_MP_WORD_BITS``: This macro controls the size of the words used for
calculations with the MPI implementation in Botan.  It must be set to either 32
or 64 bits. The default is chosen based on the target processor. There is
normally no reason to change this.

``BOTAN_DEFAULT_BUFFER_SIZE``: This constant is used as the size of
buffers throughout Botan. The default should be fine for most
purposes, reduce if you are very concerned about runtime memory usage.

Building Applications
----------------------------------------

Unix
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Botan usually links in several different system libraries (such as
``librt`` or ``libz``), depending on which modules are configured at
compile time. In many environments, particularly ones using static
libraries, an application has to link against the same libraries as
Botan for the linking step to succeed. But how does it figure out what
libraries it *is* linked against?

The answer is to ask the ``botan`` command line tool using
the ``config`` and ``version`` commands.

``botan version``: Print the Botan version number.

``botan config prefix``: If no argument, print the prefix where Botan is
installed (such as ``/opt`` or ``/usr/local``).

``botan config cflags``: Print options that should be passed to the
compiler whenever a C++ file is compiled. Typically this is used for
setting include paths.

``botan config libs``: Print options for which libraries to link to
(this will include a reference to the botan library itself).

Your ``Makefile`` can run ``botan config`` and get the options
necessary for getting your application to compile and link, regardless
of whatever crazy libraries Botan might be linked against.

Windows
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

No special help exists for building applications on Windows. However,
given that typically Windows software is distributed as binaries, this
is less of a problem - only the developer needs to worry about it. As
long as they can remember where they installed Botan, they just have
to set the appropriate flags in their Makefile/project file.

Language Wrappers
----------------------------------------

Building the Python wrappers
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The Python wrappers for Botan use ctypes and the C89 API so no special
build step is required, just import botan2.py

See :doc:`Python Bindings <python>` for more information about the
Python bindings.
