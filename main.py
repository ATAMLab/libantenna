subcommands_json = """
[
  {"name":"list", "desc":"lists avaliable subcommands", "pargs": [], "oargs": [], "flags": []},
  {"name":"freq2wavelen", "desc":"convert freqeuncy to wavelength", "pargs": [
    {"name": "freq", "desc": "frequency in Hz", "type":"float"}
  ], 
  "oargs": [], 
  "flags": [
    {"short": "", "long": "human", "desc":"human readable output"}
  ]},
  {"name":"measurement", "desc":"antenna measurement module", "subcommand": [
    {"name":"gain", "desc":"antenna gain measurement module", "subcommand": [
      {"name":"impmismatch", "desc":"gain transfer method antenna mismatch factor", "pargs": [
        {"name": "gamma_l", "desc": "antenna reflection coefficient in dB", "type":"float"},
        {"name": "gamma_s", "desc": "gain reference reflection coefficient in dB", "type":"float"}
      ], 
      "oargs": [], 
      "flags": [
        {"short": "", "long": "human", "desc":"human readable output"}
      ]}
    ]}
  ]}
]
"""

modules = """
[
]
"""

import json
import argparse
from functools import partial

parser = argparse.ArgumentParser(prog="antenna", description="Select one of the options given", formatter_class=argparse.RawDescriptionHelpFormatter)

# parser.formatter_class = lambda prog: argparse.RawTextHelpFormatter(prog, max_help_position=80)

# parser.formatter_class=newformatter
# parser.add_argument("function", help="subcommand", choices=[ obj["name"] for obj in functions ])
subparsers = parser.add_subparsers(required=True, dest="subcommand", help="<description>", metavar="<function/module>")

# subcommands
subcommands = json.loads(subcommands_json)
for subcommand in subcommands:
    if "subcommand" not in subcommand.keys():
        subcommand["parser"] = subparsers.add_parser(subcommand["name"], help="[f] " + subcommand["desc"], formatter_class=argparse.RawTextHelpFormatter)
        for parg in subcommand["pargs"]:
            subcommand["parser"].add_argument(parg["name"], help=parg["desc"], type=float if parg["type"] == "float" else int if parg["type"] == "int" else "string")
        for flag in subcommand["flags"]:
            subcommand["parser"].add_argument("--" + flag["long"], help=flag["desc"], metavar="")
    else:
        subcommand["parser"] = subparsers.add_parser(subcommand["name"], help="[m] " + subcommand["desc"], description=subcommand["desc"], formatter_class=argparse.RawTextHelpFormatter)
        subsubparsers = subcommand["parser"].add_subparsers(required=True, dest="subcommand", help="<description>", metavar="<function/module>")
        for subsubcommand in subcommand["subcommand"]:
            if "subcommand" not in subsubcommand.keys():
                subsubcommand["parser"] = subsubparsers.add_parser(subsubcommand["name"], help="[f] " + subsubcommand["desc"], formatter_class=argparse.RawTextHelpFormatter)
                for parg in subsubcommand["pargs"]:
                    subsubcommand["parser"].add_argument(parg["name"], help=parg["desc"], type=float if parg["type"] == "float" else int if parg["type"] == "int" else "string")
                for flag in subsubcommand["flags"]:
                    subsubcommand["parser"].add_argument("--" + flag["long"], help=flag["desc"], metavar="")
            else:
                subsubcommand["parser"] = subsubparsers.add_parser(subsubcommand["name"], help="[m] " + subsubcommand["desc"], description=subsubcommand["desc"], formatter_class=argparse.RawTextHelpFormatter)
                subsubsubparsers = subsubcommand["parser"].add_subparsers(required=True, dest="subcommand", help="<description>", metavar="<function/module>")
                for subsubsubcommand in subsubcommand["subcommand"]:
                    if "subcommand" not in subsubsubcommand.keys():
                        subsubsubcommand["parser"] = subsubsubparsers.add_parser(subsubsubcommand["name"], help="[f] " + subsubsubcommand["desc"], formatter_class=argparse.RawTextHelpFormatter)
                        for parg in subsubsubcommand["pargs"]:
                            subsubsubcommand["parser"].add_argument(parg["name"], help=parg["desc"], type=float if parg["type"] == "float" else int if parg["type"] == "int" else "string")
                        for flag in subsubsubcommand["flags"]:
                            subsubsubcommand["parser"].add_argument("--" + flag["long"], help=flag["desc"], metavar="")
                    else:
                        print("Error in parsing subcommands")
                        exit(1)

# # parser.add_argument("list", help="lists functions", nargs='?')
# # parser.add_argument("freq2wavelen", help="convert freqeuncy to wavelength", nargs='?')
args = parser.parse_args()
# print(subcommands[0]['parser'].parse_args())
# print(subcommands[1]['parser'].parse_args())
# parser.print_help()
print(args)
match args.subcommand:
    case "freq2wavelen":
        print(args.freq)
    case "measurement":
        print(args.measurement)
