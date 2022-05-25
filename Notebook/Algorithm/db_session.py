import traceback
from contextlib import contextmanager
import sqlalchemy

DBSession = 

@contextmanager
def session_scope():
    session = DBSession()
    try:
        yield session
        session.commit()
    except:
        session.rollback()
        raise
    finally:
        session.close()

def get_db(uuid):
    try:
        with session_scope() as session:
            res = session.query(
                tm_table,
            ).filter(
                tm_table.UUID == uuid,
            ).first()
            session.expunge_all()
    except:
        raise
    return res