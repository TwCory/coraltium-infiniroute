#!/usr/bin/env bash
set -euo pipefail
sudo clixon_backend -f /etc/clixon/clixon.conf -s
clixon_cli -f /etc/clixon/clixon.conf
