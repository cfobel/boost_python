env = Environment()
env.Append(LIBS=['python2.7', 'boost_python'])
env.Append(CPPPATH=['/usr/include/python2.7'])

env.SharedLibrary('hello_ext', 'hello_world.cpp', SHLIBPREFIX='')
env.SharedLibrary('vector_ops', 'vector.cpp', SHLIBPREFIX='')
