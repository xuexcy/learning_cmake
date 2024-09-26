#!/bin/bash
########################################################################
#
# Copyright (c) 20xx xx.com, Inc. All Rights Reserved
#
########################################################################
# Author  :   xuechengyun
# E-mail  :   xuechengyunxue@gmail.com
# Date    :   24/09/26 17:02:06
# Desc    :
########################################################################

# set -x
CUR_DIR=$(cd `dirname $0`; pwd)
cd ${CUR_DIR}


mkdir build
cd build
cmake ..
make

# 安装包
cpack -C CPackSourceConfig.cmake

# 源码包








cd -


