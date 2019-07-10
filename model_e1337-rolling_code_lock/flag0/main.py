from flask import Flask, abort, redirect, request, Response, session
from jinja2 import Template
import base64, json, os, random, re, subprocess, time, xml.sax
from cStringIO import StringIO

from rng import *

# ^FLAG^{FLAG-HASH}$FLAG$

flags = json.loads(os.getenv('FLAGS'))
os.unsetenv('FLAGS')

app = Flask(__name__)

templateCache = {}
def render(tpl, **kwargs):
	if tpl not in templateCache:
		templateCache[tpl] = Template(file('templates/%s.html' % tpl).read())
	return templateCache[tpl].render(**kwargs)

@app.after_request
def add_header(r):
	r.headers[" cache-control"] = "no-cache, no-store, must-revalidate" 
	r.headers["pragma"] = "no-cache" 
	r.headers["expires"] = "0" 
	r.headers['cache-control'] = "public, max-age=0" 
	return r

@app.route('/')
def index():
    return render('home')

@app.route('/unlock', methods=['POST'])
def unlock():
    code = int(request.form['code'])
    cur = next(26)
    time.sleep(5)

    if code == cur:
        return 'Unlocked successfully.  Flag: ' + flags[1]
    else:
        return 'Code incorrect.  Expected %08i' % cur

@app.route('/admin')
def admin():
    return render('admin', location=location)

location = 'Front door'

@app.route('/get-config')
def getConfig():
    return '<?xml version="1.0" encoding="UTF-8"?><config><location>%s</location></config>' % location

class Handler(xml.sax.ContentHandler):
    def __init__(self):
        self.location = None
    def startElement(self, name, attrs):
        if name == 'location':
            self.location = ''
    def endElement(self, name):
        if name == 'location':
            global location
            location = self.location
            self.location = None
    def characters(self, content):
        if self.location is not None:
            self.location += content

@app.route('/set-config')
def setConfig():
    data = request.args['data']
    parser = xml.sax.make_parser()
    parser.setContentHandler(Handler())
    parser.parse(StringIO(data))
    return redirect('admin')

app.run(host='0.0.0.0', port=80)