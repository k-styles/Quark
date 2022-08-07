project('QuarkChain', 'cpp', version : '1.0.0')
#version = get_option('version')
#message(version)
#
#conf_data = configuration_data()
#conf_data.set('version', version)
#cpp = meson.get_compiler('cpp')

sha = dependency('openssl', version : '>=2.5.0')
#sha = cpp.find_library('openssl', dirs : '/usr/local/lib64',required : true)
inc = include_directories ('include')

subdir('include')
subdir('src')

executable('quark', 
           'main.cc', 
            include_directories : [inc],
            link_with : [quark_lib],
            install : true,
            install_dir : 'bin/')