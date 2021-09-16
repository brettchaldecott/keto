#!/bin/bash

lib_dir() {
    echo "$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
}

docker_check_build_container_env() {
    cd $(lib_dir)/../../docker/compose-build && echo "$(docker-compose top)" && cd -
}

docker_start_build_container_env() {
    BUILD_STATUS="$(docker_check_build_container_env)"
    echo "Build status${BUILD_STATUS}"
    if [ -n "${BUILD_STATUS}" ] ;
    then
        echo "Start docker"
        cd $(lib_dir)/../../docker/compose-build && docker-compose up -d && cd -
    fi
}

docker_stop_build_container_env() {
    echo "Stop docker"
    cd $(lib_dir)/../../docker/compose-build && docker-compose stop && cd -
}

docker_execute_command() {
    COMMAND=$1
    if [ -z "$COMMAND" ] ;
    then
        echo "Docker command not provided"
        exit -1
    fi
    docker exec compose-build_build-container_1 bash -c "$COMMAND"
}


docker_start_build_container() {
    docker_start_build_container_env
}

docker_stop_build_container() {
    echo "Build Environment remains running"
}

docker_clean_build_container() {
    echo "Clean docker"
    docker_stop_build_container_env
    cd $(lib_dir)/../../docker/compose-build && docker-compose down && cd -
}
