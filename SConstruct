﻿import os
import scripts.app_helper as app

helper = app.Helper(ARGUMENTS)
helper.set_dll_def('src/slider_circle.def').set_libs(['slider_circle']).call(DefaultEnvironment)

SConscriptFiles = ['src/SConscript', 'demos/SConscript', 'tests/SConscript']
helper.SConscript(SConscriptFiles)
