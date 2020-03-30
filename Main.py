#!/usr/local/bin python3

import argparse
import sys
import serial


def main(port, baud):
    conn = serial.Serial(port, baud)
    while True:
        try:
            message = conn.readline().decode()
        except Exception:
            continue
        if message.startswith("log "):
            sys.stderr.write(message[4:])
            sys.stderr.flush()
            continue
        sys.stdout.write(message)
        sys.stdout.flush()
        if not (
            message.startswith("set") or
            message.startswith("clear")
        ):
            response = sys.stdin.readline()
            conn.write(response.encode())


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--port", required=True)
    parser.add_argument("--baud", required=True, type=int)
    args = parser.parse_args()
    main(args.port, args.baud)
