env = Environment()
env.Append(LIBS=['python2.6', 'boost_python'])
env.Append(CPPPATH=['/usr/include/python2.6'])

env.SharedLibrary('hello_ext', 'hello_world.cpp', SHLIBPREFIX='')
