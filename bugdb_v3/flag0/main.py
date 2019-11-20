from flask import Flask, abort, redirect, request, Response 
from flask_graphql import GraphQLView 
from model import db_session, Attachment 
from schema import schema 

app = Flask(__name__) 

@app.route('/') 
def main(): 
	return 'GraphiQL' 

@app.route('/attachment/')
@app.route('/attachments/') 
def attachment(id): 
	attachment = Attachment.query.filter_by(id=id).first() 
	return file('attachments/%s' % attachment.filename, 'r').read() 

app.add_url_rule('/graphql', view_func=GraphQLView.as_view('graphql', schema=schema, graphiql=True, context={'session': db_session})) 

if __name__ == "__main__": 
	app.run(host='0.0.0.0', port=80) 