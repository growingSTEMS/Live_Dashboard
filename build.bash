#! /bin/bash

build_dir=$(pwd)/build

if [[ ! -d $build_dir ]]; then
  echo "No build directory, running configure"
  ./config.bash
fi

pushd $build_dir
make
popd
