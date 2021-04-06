from flask import Flask, request, make_response,redirect, render_template

app = Flask(__name__)

todos = ['you want buy?', 'you want sell?', 'you want exit?']
#para que el template pueda utilizar esta lista necesitamos pasarla
#como parametro a render_template

@app.route('/')
def index():
    user_ip = request.remote_addr

    response = make_response(redirect('/sms'))
    response.set_cookie('user_ip',user_ip) # Poner una cookie que se llamara user ip
    return response


@app.route('/sms')
def sms():
    # para que la funcion sms obtenga el user ip directamente desde las cokies del browser 
    user_ip = request.cookies.get('user_ip')
    context = {
        'user_ip':user_ip,
        'todos': todos,
    }
    return render_template('sms.html', **context)


    
if __name__ == '__main__':
	app.run()
