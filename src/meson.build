quark_sources = ['blockchain.cc', 'block.cc', 'utils.cc']
quark_lib = shared_library('quarksrc', 
                            sources : quark_sources,
                            include_directories : [inc],
                            dependencies : [sha],
                            install : true,
                            install_dir : '../lib/')
