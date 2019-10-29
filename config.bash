#! /bin/bash

build_dir=$(pwd)/build
project_root=$(pwd)/src

if [[ ! -d $build_dir ]]; then
  mkdir $build_dir
fi

pushd $build_dir
cmake $project_root
popd
