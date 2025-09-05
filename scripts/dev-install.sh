#!/usr/bin/env bash
set -euo pipefail
sudo install -d /etc/voltos/cli /etc/voltos/yang
sudo cp -r etc/voltos/cli/*   /etc/voltos/cli/
sudo cp -r etc/voltos/yang/*  /etc/voltos/yang/
sudo cp etc/voltos/clixon.conf /etc/clixon/clixon.conf
sudo install -D build/libclixon_backend_voltos.so /usr/local/lib/libclixon_backend_voltos.so
sudo install -d /var/lib/clixon
