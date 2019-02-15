from django.shortcuts import render, get_object_or_404, redirect
from .models import Publisher
from . import forms
from .atricle_parser import article_parser_fn

def index(request): 
    last_submitted_article = Publisher.objects.order_by('-date_submitted') 
    ## pulls all artiles in DB by date submitted
    link = str(Publisher.objects.all().last())
    ##getting the url from Publisher.objects.all().last() and typecasting it to a string
    articleText = article_parser_fn(link)
    form = forms.FormName()
    ## creates a new form from our DB model in 'forms.py'
    context = {
        'last_submitted_article': last_submitted_article,
        'form':form,
        'articleText': articleText
        }
    ## context is a dictionary mapping template vars to py objects
    if request.method == 'POST':
    ## form method POST in 'index.html' html form tag (means post something)
        form = forms.FormName(request.POST)
        ## save the user submitted link to a python object
        form.save(commit=True)
        ## save the python object to the DB
        return redirect(request.path_info)
        ## redirects to same page after save is made so that form is clear and resubmission will not repeate save
   
    return render(request, 'fake_news/index.html', context)
   ## render function takes: request obj, dictionary for vars, and an optional third argument

""" 
    def detail(request, question_id):
    question = get_object_or_404(Question, pk=question_id)
    return render(request, 'polls/detail.html', {'question': question}) 
    
    <!--  <a href="{% url 'fake_news:detail' publisher.id %}/"> url tag to auto look up urls-->
    <!-- 'fake_news: defines an app anme for django to auto lookup paths in fake_news/urls.py --> 
"""